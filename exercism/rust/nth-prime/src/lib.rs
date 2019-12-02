fn is_prime(number: u32) -> bool {
    for curval in 1..number {
        if (number != curval) && ((number % curval) == 0) {
            return false;
        }
        eprintln!("{} is not divisible by {}", number, curval)
    }
    return true;
}
pub fn nth(n: u32) -> u32 {
    eprintln!(
        "starting now!"
    );
    if n == 0 {
        return 2;
    }
    let mut count: u32 = 0;
    let mut x: u32 = 1;
    while count <= n {
        x += 1;
        eprintln!("x is {} and count is {}", x, count);
        if is_prime(x) {
            count += 1;
        }
        eprintln!("x is {} and count is {}", x, count);
    }
    x
}
