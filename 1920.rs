use std::io::{self, BufRead, StdinLock, Lines};
use std::io::Write;

fn main() {
    let mut lines = io::stdin().lock().lines();
    line2i32vec(&mut lines);
    let mut a = line2i32vec(&mut lines);
    a.sort_unstable();
    line2i32vec(&mut lines);
    let b = line2i32vec(&mut lines);

    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());
    for m in b {
        writeln!(out, "{}", if a.binary_search(&m).is_ok() { 1 } else { 0 });
    }
}

fn line2i32vec(lines: &mut Lines<StdinLock>) -> Vec<i32> {
    let l = lines.next().unwrap().expect("Failed to read a line");

    l.trim().split_ascii_whitespace().map(|x| x.parse().expect("an integer")).collect()
}