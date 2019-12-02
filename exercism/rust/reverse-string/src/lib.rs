extern crate unicode_segmentation;

use unicode_segmentation::UnicodeSegmentation;

pub fn reverse(input: &str) -> String {
    let chars = input.graphemes(true);
    let mut out = String::with_capacity(input.len());
    for chr in chars.rev() {
        out.push_str(chr);
    }
    out
}
