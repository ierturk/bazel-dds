fn main() {
    println!("Hello from Rust!");
}

#[cfg(test)]
mod tests {
    // use super::*;

    #[test]
    fn placeholder_test() {
        assert_eq!(2 + 2, 4); // Placeholder test
    }
}