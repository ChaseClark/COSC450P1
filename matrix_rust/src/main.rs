use std::fs;

fn main() {
    let mut input_vec: Vec<i32> = create_vec_from_file();

    println!("\nPrinting out the vector!\n");
    for i in input_vec {
        println!("{}", i);
    }
}

fn create_vec_from_file() -> Vec<i32> {
    let mut vec: Vec<i32> = Vec::new();
    let filename = "input.txt";

    println!("In file {}\n", filename);

    let contents = fs::read_to_string(filename).expect("Something went wrong reading the file.");

    println!("Contents: {}\n", contents);

    let split = contents.split(" ");

    for s in split {
        println!("{}", s);
        vec.push(s.parse::<i32>().unwrap());
    }
    vec;
}
