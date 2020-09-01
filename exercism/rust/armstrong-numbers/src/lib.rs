pub fn is_armstrong_number(num: u32) -> bool {
    let mut n = num;
    let mut len = 1;
    let mut numbers: Vec<u32> = vec![];
    loop {
        let rem = n % 10;
        numbers.push(rem);
        if rem == n {
            break;
        }
        len += 1;
        n /= 10;
    }
    numbers.iter().fold(0, |acc, el| acc + el.pow(len)) == num
}
