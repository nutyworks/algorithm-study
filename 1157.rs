use std::{io, collections::HashMap};

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s);

    let s = s.trim().to_ascii_uppercase();
    let mut counter = HashMap::new();

    s.chars().for_each(|ch| {
        let entry = counter.entry(ch).or_insert(0u32);
        *entry += 1;
    });

    let result = counter.iter().fold((' ', 0u32), |max, new| {
        match max.1.cmp(new.1) {
            std::cmp::Ordering::Equal => ('?', max.1),
            std::cmp::Ordering::Greater => max,
            std::cmp::Ordering::Less => (*new.0, *new.1),
        }
    }).0;

    println!("{}", result);
}
