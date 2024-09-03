/**
 * 17951 흩날리는 시험지 속에서 내 평점이 느껴진거야
 * https://www.acmicpc.net/problem/17951
 * 
 * @author minchae
 * @date 2024. 8. 28.
 * */

import java.util.*;
import java.io.*;

public class BOJ_17951 {
	
	static int N, K;
	static int[] score;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		score = new int[N];
		
		st = new StringTokenizer(br.readLine());
		
		int end = 0;
		
		for (int i = 0; i < N; i++) {
			score[i] = Integer.parseInt(st.nextToken());
			end += score[i];
		}
		
		int start = 0;
		
		System.out.println(getMax(start, end));
	}

	// 최대 점수 계산
	private static int getMax(int start, int end) {
		while (start <= end) {
			int mid = (start + end) / 2;
			
			int cnt = 0;
			int sum = 0;
			
			for (int num : score) {
				sum += num;
				
				if (sum >= mid) {
					sum = 0;
					cnt++;
				}
			}
			
			if (K <= cnt) {
				start = mid + 1;
			} else {
				end = mid - 1;
			}
		}
		
		return end;
	}
}
