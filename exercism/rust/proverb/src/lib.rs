pub fn build_proverb(list: &[&str]) -> String {
    if list.len() < 1 {
        return String::new();
    }
    let mut verses: Vec<String> = (0..list.len() - 1)
        .map(|i| format!("For want of a {} the {} was lost.", list[i], list[i + 1],))
        .collect();
    verses.push(format!("And all for the want of a {}.", list[0]));
    verses.join("\n")
}
