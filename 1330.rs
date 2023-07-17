use std::{io, cmp::Ordering};

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s);
    let ns: Vec<i16> = s.trim().split_ascii_whitespace().map(|x| x.parse().expect("not integer")).collect();

    let result = match ns[0].cmp(&ns[1]) {
        Ordering::Less => "<",
        Ordering::Equal => "==",
        Ordering::Greater => ">",
    };

    println!("{}", result);
}