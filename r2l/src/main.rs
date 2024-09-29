use std::env;
use std::io;

mod modules {
    pub mod readfile;
    pub mod parse;
}

fn main() -> io::Result<()> {
    // Get the file name from the command-line arguments
    let args: Vec<String> = env::args().collect();
    if args.len() < 2 {
        eprintln!("Usage: {} <filename>", args[0]);
        return Ok(());
    }

    // Pass the file name argument as a &str to the readfile function
    let filename = &args[1]; // Take a reference to the filename (which is a String)

    // Call the readfile function and handle the result
    match modules::readfile::readfile(filename) {
        Ok(()) => println!("File read successfully!"),
        Err(e) => eprintln!("Error reading file: {}", e),
    }

    Ok(())
}
