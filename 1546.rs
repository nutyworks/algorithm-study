use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    lines.next();
    let s = lines.next().unwrap().unwrap();
    let ns: Vec<i32> = s.split_ascii_whitespace().map(|x| x.parse().expect("an integer")).collect();

    let max = *ns.iter().max().expect("non-emtpy vector");
    let sum: i32 = ns.iter().sum();
    let size = ns.len();

    println!("{}", sum as f32 / max as f32 / size as f32 * 100f32);
}
