package Practice;


public class BinarySearch {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr = {1};
		System.out.println(BS_equal_greater(arr, 30));
		System.out.println(BS_less(arr, 30));
		System.out.println(BS_equal_less(arr, 30));
		System.out.println(BS_greater(arr, 30));
		System.out.println(BS_equal(arr, 30));
	}
	
	public static int BS_equal_greater(int[] arr, int target){
		int l = 0;
		int r = arr.length;
		while(l < r){
			int m = (r - l) / 2 + l;
			if(arr[m] < target) l = m + 1;
			else r = m;
		}
		return l;
	}

	public static int BS_less(int[] arr, int target){
		int l = 0;
		int r = arr.length;
//Can be seen as finding the first equal or greater and minus 1
		while(l < r){
			int m = (r - l) / 2 + l;
			if(arr[m] < target) l = m + 1;
			else r = m;
		}
		return l - 1;
	}
	
	public static int BS_equal_less(int[] arr, int target){
		int l = 0;
		int r = arr.length;
		while(l < r){
			int m = (r - l) / 2 + l;
			if(arr[m] <= target) l = m + 1;
			else r = m;
		}
		return l - 1;
	}

	public static int BS_greater(int[] arr, int target){
		int l = 0;
		int r = arr.length;
		while(l < r){
			int m = (r - l) / 2 + l;
			if(arr[m] <= target) l = m + 1;
			else r = m;
		}
		return l;
	}
	
	public static int BS_equal(int[] arr, int target){
		int l = 0;
		int r = arr.length;
		while(l < r){
			int m = (r - l) / 2 + l;
			if(arr[m] < target) l = m + 1;
			else r = m;
		}
		return l != arr.length && arr[l] == target ? l : -1 ;
	}
}
