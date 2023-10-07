import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

	static int cnt;
	static List <Integer> smallList = new ArrayList<>();
	static List <Integer> bigList = new ArrayList<>();
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long A = Long.parseLong(br.readLine());
		long X = A;
	
		while(A > 0L) {
			smallList.add((int)(A%2));
			bigList.add((int)(A%2));
			if((int)(A%2)==1)
				cnt++;
			A = A/2;
		}
		smallList.add(0);
		bigList.add(0);
		System.out.println(small() + " " +big());
	}
	public static long small() {
		int i;
		for(i = 1; i < smallList.size();i++) {
			if(smallList.get(i) == 1 && smallList.get(i-1) == 0) {
				smallList.set(i, 0);
				smallList.set(i-1, 1);
				break;
			}
		}
		if(i == smallList.size())
			return 0;
		for(int j = 0; j < i;j++) {
			smallList.set(j, 0);
		}
		int count = 0;
		for(int j = 0; j <smallList.size();j++) {
			if(smallList.get(j) == 1)
				count++;
		}
		for(int j = 0; j < cnt - count; j++) {
			smallList.set(i-1-j, 1);
		}
		return toDecimal(smallList);
	}
	public static long big() {
		int i;
		for(i = 1; i < bigList.size();i++) {
			if(bigList.get(i) == 0 && bigList.get(i-1) == 1) {
				bigList.set(i, 1);
				bigList.set(i-1, 0);
				break;
			}
		}
		if(i == bigList.size())
			return 0;
		for(int j = 0; j < i;j++) {
			bigList.set(j, 0);
		}
		int count = 0;
		for(int j = 0; j <bigList.size();j++) {
			if(bigList.get(j) == 1)
				count++;
		}
		for(int j = 0; j < cnt - count; j++) {
			bigList.set(j, 1);
		}
		return toDecimal(bigList);
		
	}
	public static Long toDecimal(List<Integer> list) {
		Long result = 0L;
		Long bin = 1L;
		for(int i = 0; i < list.size(); i++) {
			result += bin * (long)list.get(i);
			bin *= 2L;
		}
		
		return result;
	}
}