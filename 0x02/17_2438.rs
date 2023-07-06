use std::io;

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s);
    let n: i32 = s.trim().parse().expect("an integer");

    for j in 1..=n {
        for i in 1..=j {
            print!("*");
        }
        println!();
    }
}