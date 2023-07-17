use std::io;

fn main() {
    let mut s = String::default();
    io::stdin().read_line(&mut s).unwrap();
    println!("{}", s.trim().split_ascii_whitespace().count())
}
