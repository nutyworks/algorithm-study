use std::io;

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s);
    let n: i32 = s.trim().parse().expect("an integer");

    for j in 1..=n {
        for _ in 0..(n-j) {
            print!(" ");
        }
        for _ in 1..=j {
            print!("*");
        }
        println!();
    }
}