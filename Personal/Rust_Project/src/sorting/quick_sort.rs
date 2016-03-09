pub fn sort(list: &mut Vec<i32>) {
    let mut smaller: Vec<i32> = Vec::new();
    let mut equal: Vec<i32> = Vec::new();
    let mut bigger: Vec<i32> = Vec::new();

    let pivot = list[0];

    for i in list.iter() {
        if *i < pivot {
            smaller.push(*i);
        } else if *i == pivot {
            equal.push(*i);
        } else {
            bigger.push(*i);
        }
    }

    list.clear();

    smaller.shrink_to_fit();
    equal.shrink_to_fit();
    bigger.shrink_to_fit();

    vector_append(list, sort_r(&mut smaller));
    vector_append(list, &mut equal);
    vector_append(list, sort_r(&mut bigger));

    list.shrink_to_fit();
}

fn sort_r(list: &mut Vec<i32>) -> &mut Vec<i32> {
    if list.len() <= 1 {
        return list;
    }

    let mut smaller: Vec<i32> = Vec::new();
    let mut equal: Vec<i32> = Vec::new();
    let mut bigger: Vec<i32> = Vec::new();

    let pivot = list[0];

    for i in list.iter() {
        if *i < pivot {
            smaller.push(*i);
        } else if *i == pivot {
            equal.push(*i);
        } else {
            bigger.push(*i);
        }
    }

    list.clear();

    smaller.shrink_to_fit();
    equal.shrink_to_fit();
    bigger.shrink_to_fit();

    vector_append(list, sort_r(&mut smaller));
    vector_append(list, &mut equal);
    vector_append(list, sort_r(&mut bigger));

    list.shrink_to_fit();

    list
}

fn vector_append(list1: &mut Vec<i32>, list2: &mut Vec<i32>){
    for i in list2.iter() {
        list1.push(*i);
    }
}
