mod isbn {
    use std::{convert::TryInto, error::Error, fmt, fmt::Display};
    pub struct ISBN {
        data: [i8; 9],
        check: i8,
    }

    #[derive(Debug)]
    pub struct InvalidISBN {
        values: Vec<i8>,
    }

    impl InvalidISBN {
        fn new(data: [i8; 9], check: i8) -> Self {
            let data: &[i8] = &data;
            let mut this = InvalidISBN {
                values: Vec::from(data),
            };
            this.values.push(check);
            this
        }
    }

    impl Error for InvalidISBN {}

    impl Display for InvalidISBN {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            write!(f, "received invalid ISBN digits {:?}", self.values)
        }
    }

    pub struct InvalidISBNText {
        text: String,
        msg: Option<String>,
    }
    impl Display for InvalidISBNText {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            let msg = self.msg.clone();
            write!(
                f,
                r#"the text "{}" was not a valid ISBN-10 {}"#,
                self.text,
                if let Some(message) = msg {
                    format!(", because {}", message)
                } else {
                    String::default()
                }
            )
        }
    }
    impl InvalidISBNText {
        fn new(text: String) -> Self {
            Self {
                text: text,
                msg: None,
            }
        }
        fn with_msg(text: String, msg: String) -> Self {
            Self {
                text: text,
                msg: Some(msg),
            }
        }
    }

    impl ISBN {
        pub fn new(data: [i8; 9], check: i8) -> Result<ISBN, InvalidISBN> {
            ISBN { data, check }.validate()
        }
        fn validate(self) -> Result<ISBN, InvalidISBN> {
            let mut index = 10;

            let vsum: u32 = self.data.into_iter().fold(0_u32, |sum, digit| {
                println!("sum: {}, digit: {}, index: {}", sum, digit, index);
                let sum: u32 = sum + digit.try_into().unwrap() * index;
                index -= 1;
                sum
            }) + self.check.try_into().unwrap();
            if vsum % 11 == 0 {
                Ok(self)
            } else {
                Err(InvalidISBN::new(self.data, self.check))
            }
        }
        pub fn from_s(text: String) -> Result<ISBN, InvalidISBNText> {
            let chars = text.chars();
            let mut data = [0_i8; 9];
            let mut check = Some(0);
            for (i, digit) in chars.filter(char::is_ascii_digit).enumerate() {
                if i == 9 {
                    check = if digit == 'X' {
                        Some(10)
                    } else {
                        digit.to_digit(10)
                    };
                    break;
                }
                if let Some(dgt) = digit.to_digit(10) {
                    if let Ok(d) = dgt.try_into() {
                        data[i] = d;
                    } else {
                        return Err(InvalidISBNText::with_msg(text, format!("by some insanity, we got a single digit that doesn't fit into an i8")));
                    }
                } else {
                    return Err(InvalidISBNText::with_msg(
                        text,
                        format!("'{}' is not a valid decimal digit", digit),
                    ));
                }
            }
            if let Some(check_val) = check {
                let bn = ISBN::new(data, check_val.try_into().unwrap());
                if let Ok(num) = bn {
                    Ok(num)
                } else {
                    Err(InvalidISBNText::new(text))
                }
            } else {
                Err(InvalidISBNText::with_msg(
                    text,
                    format!("'{:?}' was neither X nor a valid radix digit.", check),
                ))
            }
        }
    }

}
/// Determines whether the supplied string is a valid ISBN number
pub fn is_valid_isbn(isbn: &str) -> bool {
    let number = isbn::ISBN::from_s(String::from(isbn));
    if let Ok(_bn) = number {
        true
    } else {
        false
    }
}
