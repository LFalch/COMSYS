#![feature(int_log)]

use rand::prelude::random;

#[derive(Debug, Copy, Clone)]
struct Line<const B: usize> {
    valid: bool,
    tag: usize,
    bytes: [u8; B],
}

impl<const B: usize> Line<B> {
    const fn new() -> Self {
        Line {
            valid: false,
            tag: 0,
            bytes: [0; B],
        }
    }
}

struct Cache<F: FnMut(usize) -> [u8; B], const S: usize, const E: usize, const B: usize> {
    sets: [[Line<B>; E]; S],
    fetch_on_miss: F,
}

use std::fmt::{self, Debug};

impl<F: FnMut(usize) -> [u8; B], const S: usize, const E: usize, const B: usize> Debug for Cache<F, S, E, B> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        f.debug_struct("Cache")
        .field("sets", &self.sets)
        .field("fetch_on_miss", &())
        .finish()
    }
}

const M_BITS: usize = 64;

/// splits into (tag, set_index, block_offset)
const fn split_address<const S: usize, const B: usize>(address: usize) -> (usize, usize, usize) {
    let tag = address >> (S.log2() + B.log2());
    let set_index = (address >> B.log2()) & (S - 1);
    let block_offset = address & (B - 1);

    (tag, set_index, block_offset)
}

impl<F: Fn(usize) -> [u8; B], const S: usize, const E: usize, const B: usize> Cache<F, S, E, B> {
    #[inline]
    fn new(fetch_on_miss: F) -> Self {
        assert_eq!(S.count_ones(), 1);
        assert_eq!(E.count_ones(), 1);
        assert_eq!(B.count_ones(), 1);
        Self {
            sets: [[Line::new(); E]; S],
            fetch_on_miss,
        }
    }
    fn lookup(&self, address: usize) -> Option<usize> {
        let (tag, set_index, _) = split_address::<S, B>(address);

        self.sets[set_index]
            .iter()
            .enumerate()
            .find(|(_, line)| line.valid && line.tag == tag)
            .map(|(i, _)| i)
    }
    fn fetch(&mut self, address: usize) -> usize {
        let (tag, set_index, _) = split_address::<S, B>(address);
        let bytes = (self.fetch_on_miss)((tag << S.log2() + B.log2()) | (set_index << B.log2()));

        for (i, line) in self.sets[set_index].iter_mut().enumerate() {
            if !line.valid {
                *line = Line {
                    valid: true,
                    tag,
                    bytes,
                };
                return i;
            }
        }
        let index_to_evict = random::<usize>() & (E-1);
        let line = &mut self.sets[set_index][index_to_evict];
        *line = Line {
            valid: true,
            tag,
            bytes,
        };
        return index_to_evict;
    }
    pub fn hit_or_miss(&mut self, address: usize) -> &u8 {
        let line_index = if let Some(i) = self.lookup(address) {
            i
        } else {
            self.fetch(address)
        };

        let (_, set_index, bo) = split_address::<S, B>(address);
        &self.sets[set_index][line_index].bytes[bo]
    }
}

fn miss_fetch(i: usize) -> [u8; 16] {
    let i = i as u8;
    println!("Miss!");
    [
        i,
        i.wrapping_add(1),
        i.wrapping_add(2),
        i.wrapping_add(3),
        i.wrapping_add(4),
        i.wrapping_add(5),
        i.wrapping_add(6),
        i.wrapping_add(7),
        i.wrapping_add(8),
        i.wrapping_add(9),
        i.wrapping_add(10),
        i.wrapping_add(11),
        i.wrapping_add(12),
        i.wrapping_add(13),
        i.wrapping_add(14),
        i.wrapping_add(15),
    ]
}

fn main() {
    let mut cache = Cache::<_, 1, 2, 16>::new(miss_fetch);
    println!("#9: {}", cache.hit_or_miss(9));
    println!("#10: {}", cache.hit_or_miss(10));
    println!("#11: {}", cache.hit_or_miss(11));
    println!("#12: {}", cache.hit_or_miss(12));
    println!("#13: {}", cache.hit_or_miss(13));
    println!("#14: {}", cache.hit_or_miss(14));
    println!("#15: {}", cache.hit_or_miss(15));
    println!("#16: {}", cache.hit_or_miss(16));
    println!("#17: {}", cache.hit_or_miss(17));
    println!("#0: {}", cache.hit_or_miss(0));
    println!("#9132842134: {}", cache.hit_or_miss(9132842134));
    println!("#0: {}", cache.hit_or_miss(0));
    println!("#9132842134: {}", cache.hit_or_miss(9132842134));
    // println!("{:#?}", &cache);
}
