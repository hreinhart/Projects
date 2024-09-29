use std::fs::File;
use std::io::{self, Read};

pub fn readfile (args: &str) -> String {
    
    let filename = args;
    
    //Format file path
    let filepath = format!("{}/{}/{}","src","tests",filename);
    
    // Open the file
    let mut file = File::open(filepath)?;

    // Create a string to hold the file content
    let mut content = String::new();

    // Read the file content into the string
    file.read_to_string(&mut content)?;

    // Print the file content
    println!("File Content of {}: \n{}", filename, content);

    content

}