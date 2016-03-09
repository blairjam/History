mod sorting;

fn main() {
    let mut list = vec![9, 4, 2, 7, 8, 9, 6, 0, 1, 12, 18, 3, 5];

    //sorting::merge_sort::sort(&mut list);
    sorting::quick_sort::sort(&mut list);

    for i in list.iter() {
        println!("{}", i);
    }

    sorting::merge_sort::sort(&mut list);
}
