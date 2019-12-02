pub fn square(s: u32) -> u64 {
    if 1 > s || s > 64 {
        panic!("Square must be between 1 and 64");
    }
    2_u64.pow(s - 1)
}

pub fn total() -> u64 {
    (1..=64).map(|n| square(n)).sum::<u64>()
}
