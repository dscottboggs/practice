use std::cmp;
use std::iter::Iterator;

#[derive(Debug)]
pub struct HighScores<'a> {
    scores: &'a [u32],
}

impl<'a> HighScores<'a> {
    pub fn new(scores: &'a [u32]) -> Self {
        Self { scores: scores }
    }

    pub fn scores(&self) -> &[u32] {
        self.scores
    }

    pub fn latest(&self) -> Option<u32> {
        match self.scores.len() {
            0 => None,
            n => Some(self.scores[n - 1]),
        }
    }

    fn max_of(current_max: u32, score: &u32) -> u32 {
        cmp::max(current_max, *score)
    }
    pub fn personal_best(&self) -> Option<u32> {
        match self.scores.len() {
            0 => None,
            _ => Some(self.scores.into_iter().fold(0, &Self::max_of)),
        }
    }

    pub fn personal_top_three(&self) -> Vec<u32> {
        match self.scores.len() {
            0 => vec![],
            n if n >= 3 => {
                let mut sorted = self.scores.to_vec();
                sorted.sort();
                sorted[n - 3..n].iter().rev().map(|&it| it).collect()
            }
            _ => {
                let mut sorted = self.scores.to_vec();
                sorted.sort();
                sorted.iter().rev().map(|&it| it).collect()
            }
        }
    }
}
