use std::collections::HashSet;
use std::iter::FromIterator;

struct CheckForAnagram<'result_life> {
    word: String,
    result: HashSet<&'result_life str>
}

impl<'result_life> CheckForAnagram<'result_life> {
    fn from(word: &str) -> Self {
        CheckForAnagram {
            word: String::from(word).to_lowercase(),
            result: HashSet::new()
        }
    }
    fn in_word(&mut self, possible_anagram: &'result_life str) {
        let possible_anagram = possible_anagram.to_lowercase();
        let set: HashSet<char> = possible_anagram.chars().collect();
        if self.word == possible_anagram {
            return
        }
        let anagram = self.word.chars().all(|c| {
            if let Some(_) = set.get(&c) {
                true
            } else {
                false
            }
        });
        if anagram {
            self.result.insert(possible_anagram.as_str());
        }
    }
    fn found(&self) -> HashSet<&'result_life str> {
        self.result.clone()
    }
}

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &[&'a str]) -> HashSet<&'a str> {
    let mut check_for_anagram: CheckForAnagram<'a> = CheckForAnagram::from(word);
    for possible_anagram in possible_anagrams {
        check_for_anagram.in_word(possible_anagram)
    }
    check_for_anagram.found()
}
