struct Solution {}

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        for i in 0..nums.len() {
            for j in i+1..nums.len() {
                if nums[i] + nums[j] == target { return vec![i as i32, j as i32]; }
            }
        }
        vec![]
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_0001() {
        let v: Vec<i32> = vec![2, 7, 11, 15];
        let result = Solution::two_sum(v, 9);
        println!("{:?}", result);
        assert_eq!(result, vec![0, 1]);
    }
}