##Pylons  

### Description


* Give N * M grid.	
* In the restraint that this robot can't walk to herizontal, vertical and diagonal grids.
* Ask how to traverse all the grids exactly once.
* N, M <= 20, T <= 100

### Thoughts

* Try and error all the odds => (NM)!
* Cut unecessary lines:
	* N == 1 | M == 1  => Impposible
* Find a general rule to build:
	* Observe the number of ways for each grids.
		* It'll be smaller in the center.
	* How shall I run it on my own?
		* Look at the number of ways for (N,M) = (3, 4)
		* Suppose we all start at (1,1); because I believe that a possible (N,M) case must have solutions no matter where we start. 	
		=> I have no idea how to prove it yet.
		* It will be esier if we travel the center as soon as possible.		
		* Epiphany about the below traverse.	
		We can make some alternative position change meanwhile solving the centre grids.	
		This alternative method I came up with accidentally seems to solve the problem that the grids we chose may be too close.	
		In total, even rows start from the booundary; odd rows start from the center.	
	* How the hell can I prove the certainty? Totally no clue.
	* Implementation time~
	* Debug:
		* There is still some bias, or the same problem metioned above, that for one row we should take the left or right for start.	
		* Handle it by random values eventually.
	* Improvements:
		* Tried using my observations to cut more lines and traversing like the first thought. (idea couraged by _chi_)		
		Still needed random values to speed up.		
		time, tested by T=400 for ([1, 20],[1, 20]):	
			
|      | -  | improved |
|---   |---|---|
| real | 0m0.026s | 0m0.255s |
| user | 0m0.015s | 0m0.242s | 
| sys  | 0m0.008s | 0m0.009s |
		
		

|   |   |   |   |
|---|---|---|---|
| 1 | 10 | 7 | 4 |
| 8 | 5 | 2 |  11 | 
| 3 | 12 | 9 | 6 | 
	



