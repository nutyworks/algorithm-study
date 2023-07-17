use std::io;

fn main() {
    let mut s = String::default();
    io::stdin().read_line(&mut s).expect("Failed to read line");
    let inputs: Vec<i64> = s.trim()
        .split_ascii_whitespace()
        .map(|x| x.parse().expect("Not an integer"))
        .collect();

    println!("{}", inputs[0] + inputs[1] + inputs[2]);
}