use std::io;

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s);
    let result: i32 = s.trim().split_ascii_whitespace()
        .map(|x| x.parse::<i32>().expect("an integer"))
        .map(|x| x * x).sum::<i32>() % 10;
    println!("{}", result);
}
