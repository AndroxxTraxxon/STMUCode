import java.util.Arrays;

public class FunTiming {
	public static void main(String args[]){
		System.out.println("Hello World!");
		testFunctions(10000);
	}
	
	static void testFunctions(int n){
		long times[][] = new long[6][7];
		int sums[][] = new int[6][6];
		for(int i = 0; i < 6; i++){
			long k = n * (2*i + 1);
			times[i][0] = System.nanoTime();
			sums[i][0] = fun1(k);
			times[i][1] = System.nanoTime();
			sums[i][1] = fun2(k);
			times[i][2] = System.nanoTime();
			sums[i][2] = fun3(k);
			times[i][3] = System.nanoTime();
			sums[i][3] = fun4(k);
			times[i][4] = System.nanoTime();
			sums[i][4] = fun5(k);
			times[i][5] = System.nanoTime();
			sums[i][5] = fun6(k);
			times[i][6] = System.nanoTime();
		}
		
		long processedTimes[][] = new long[6][6];
		double processedLogs[][] = new double[6][6];
		for(int i = 0; i < 6; i++){
			double factor = Math.pow(n, i);
			for(int j = 0; j < 6; j++){
				processedTimes[i][j] = times[i][j+1] - times[i][j];
				processedLogs[i][j] = Math.log(processedTimes[i][j]);
			}
		}
		
		System.out.println("Sums");
		for(int i = 0; i < 6; i++){
			System.out.println("Input = " + (int)n * (2*i + 1) + ":" +Arrays.toString(sums[i]));
		}
		System.out.println("Process times [Nanoseconds or light-feet]");
		for(int i = 0; i < 6; i++){
			System.out.println("Input = " + (int)(n * (2*i + 1)) + ":" +Arrays.toString(processedTimes[i]));
		}
		System.out.println("Log ratios");
		for(int i = 0; i < 6; i++){
			System.out.println("Input = " + (int)(n * (2*i + 1)) + ":" +Arrays.toString(processedLogs[i]));
		}
		
		
	}

	static int fun1(long n){
		System.out.println("Starting Fun1("+n+").");
		int sum = 0;
		for(int i=0; i<n; i++){
			sum++;
		}
		//System.out.println(sum);
		return sum;
	}
	
	static int fun2(long n){
		System.out.println("Starting Fun2("+n+").");
		int sum = 0;
		for(int i=0; i < n; i++ )
			for(int j=0; j < n; j++ )
				sum++;
		//System.out.println(sum);
		return sum;
	}
	static int fun3(long n){
		System.out.println("Starting Fun3("+n+").");
		int sum = 0;
		for(int i=0; i < n; i++ )
			for(int j=0; j<n*n; j++ )
				sum++;
		//System.out.println(sum);
		return sum;
	}
	
	static int fun4(long n){
		System.out.println("Starting Fun4("+n+").");
		int sum = 0;
		for(int i=0; i<n; i++ )
			for(int j=0; j<i; j++ )
				sum++;
		//System.out.println(sum);
		return sum;
	}
	static int fun5(long n){
		System.out.println("Starting Fun5("+n+").");
		int sum = 0;
		for(int i=0; i<n; i++ )
			for(int j=0; j< i*i; j++ )
				for(int k=0; k<j; k++)
					sum++;
		//System.out.println(sum);
		return sum;
	}
	static int fun6(long n){
		System.out.println("Starting Fun6("+n+").");
		int sum = 0;
		for(int i=1; i<n; i++ )
			for(int j=1; j<i*i; j++ )
				if( j%1 == 0 )
					for(int k=0; k<j; k++ )
						sum++;
		//System.out.println(sum);
		return sum;
	}
}