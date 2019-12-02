/// "Encipher" with the Atbash cipher.
pub fn encode(plain: &str) -> String {
    let mut output = String::default();
    for (i, chr) in decode(plain).chars().enumerate() {
        if i % 5 == 0 && i != 0 {
            output.push(' ');
        }
        output.push(chr);
    }
    output
}

// Swap characters by subtracting the character from the maximum possible in
// the ASCII range ('z' or 0x7A) and then adding the minimum possible ASCII
// range ('a' or 0x61).
fn encode_char(chr: char) -> char {
    let chr = chr.to_ascii_lowercase();
    if chr.is_ascii_digit() {
        chr
    } else if chr.is_ascii_lowercase() {
        (b'z' - chr as u8 + b'a') as char
    } else {
        panic!("encode_char() recieved invalid character '{}'.", chr);
    }
}

/// "Decipher" with the Atbash cipher.
pub fn decode(cipher: &str) -> String {
    String::from(cipher)
        .chars()
        .filter(char::is_ascii_alphanumeric)
        .map(encode_char)
        .collect::<String>()
}
