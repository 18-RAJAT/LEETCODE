impl Solution {
    pub fn get_smallest_string(s: String) -> String {
        let mut s=s.into_bytes();
        for i in 0..s.len()-1
        {
            if s[i]%2==s[i+1]%2 && s[i+1]<s[i]
            {
                s.swap(i,i+1);
                break;
            }
        }
        //Convert Vec<u8> back to String
        String::from_utf8(s).unwrap()
    }
}