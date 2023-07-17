use std::io::{self, BufRead};

fn main() {
    let mut lines = io::stdin().lock().lines();
    let mut max = 0;
    let mut max_i = 0;

    for i in 1..=9 {
        let n: i32 = lines.next().unwrap().unwrap().parse().expect("an integer");

        if max < n {
            max = n;
            max_i = i;
        }
    }

    println!("{max}\n{max_i}");
}
