use std::cmp::Ordering::*;

#[derive(Debug, PartialEq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

fn is_sublist<T: PartialEq>(one: &[T], two: &[T]) -> bool {
    two.windows(one.len()).any(|window| window == one)
}

pub fn sublist<T: PartialEq>(one: &[T], two: &[T]) -> Comparison {
    match (one.len(), two.len()) {
        (0, 0) => Comparison::Equal,
        (0, _) => Comparison::Sublist,
        (_, 0) => Comparison::Superlist,
        (len_one, len_two) => match len_one.cmp(&len_two) {
            Equal if one == two => Comparison::Equal,
            Less if is_sublist(one, two) => Comparison::Sublist,
            Greater if is_sublist(two, one) => Comparison::Superlist,
            _ => Comparison::Unequal,
        },
    }
}
