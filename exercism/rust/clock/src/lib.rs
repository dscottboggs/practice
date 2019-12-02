#![feature(euclidean_division)]
use std::fmt::{Debug, Display};
#[derive(PartialEq, Eq, Debug)]
pub struct Clock {
    minutes: i32, // the count of minutes since midnight
}
const MINUTES_PER_DAY: i32 = 24 * 60;
fn checked(minutes: i32) -> i32 {
    minutes.rem_euclid(MINUTES_PER_DAY)
}
impl Clock {
    fn hours(&self) -> i32 {
        self.minutes / 60
    }
    fn minutes_this_hour(&self) -> i32 {
        self.minutes % 60
    }
    fn from_minute_count(minutes: i32) -> Self {
        Clock{minutes: checked(minutes)}
    }
    pub fn new(hours: i32, minutes: i32) -> Self {
        Clock::from_minute_count((hours * 60) + minutes)
    }
    pub fn add_minutes(&self, minutes: i32) -> Self {
        Clock::from_minute_count(self.minutes + minutes)
    }
}

impl Display for Clock {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        write!(f, "{:02}:{:02}", self.hours(), self.minutes_this_hour())
    }
}
