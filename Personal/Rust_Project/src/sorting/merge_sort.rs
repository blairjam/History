pub fn sort(list: &mut Vec<i32>) -> &mut Vec<i32> {
     if list.len() <= 1 {
        return list;
     }

     let middle = list.len() / 2;

     let mut beginning: Vec<i32> = list[0..middle];
     let mut end: Vec<i32> = list[middle..];

     println!("{:?}", beginning);
     println!("{:?}", end);

     list
}
