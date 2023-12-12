// Optimized javaScript implementation
// of Bubble sort
// An optimized version of Bubble Sort
function bubbleSort(arr, n)
{
	var i, j, temp;
	var swapped;
	for (i = 0; i < n - 1; i++)
	//0 s/d 8-1 = 0-7 
	{
		swapped = false;
		//0 s/d 8-0-1 // 0 s/d 7 //perulangan luar pertama 
		for (j = 0; j < n - i - 1; j++)//n=8 
		{
            // [ 64, 34, 25, 12, 22, 11, 90 ,0]; //8
			if (arr[j] > arr[j + 1])
			// array ke 0 lebih besar dari array 1 maka di swap  
		    // array ke 1 diisi oleh 64 
			{
				// Swap arr[j] and arr[j+1]
				temp = arr[j]; //temp = 64
				arr[j] = arr[j + 1];  //ar[j] = 34
				arr[j + 1] = temp; 
				// 34,64,25,12 ......//perulangan pertama
				// 34,64,25,12
				//dst
				//pada iterasi 6 sementara berhenti karena dia dihadapkan oleh 90
				//34,25,12,22,64,0,90
				//outer 0 baru selesei
				//setelah itu outer 1 dijalankan 
				//kalau outer 1 dijalankan maka perulangan dimulai dari 0 - 6
				//34,25,12,22,11,64,0,90
				swapped = true; 	
			}
		}
		// IF no two elements were 
		// swapped by inner loop, then break
		if (swapped == false)
		break;
	}
}
// Function to print an array 
function printArray(arr, size)
{
var i;
for (i = 0; i < size; i++)
	console.log(arr[i] + " ");
}

// Driver program
var arr = [ 64, 34, 25, 12, 22, 11, 90 ,0];
var n = arr.length;
bubbleSort(arr, n);
console.log("Sorted array: ");
printArray(arr, n);

// This code is contributed shivanisinghss2110
//penjelasan yang tepat 

// Output per iterasi bubble sort:

// Iterasi 1:

// Lingkup luar: i = 0
// Lingkup dalam:
// j = 0, bandingkan 64 dan 34. Tukar karena 64 > 34. Sekarang array adalah [34, 64, 25, 12, 22, 11, 90, 0].
// j = 1, bandingkan 64 dan 25. Tukar karena 64 > 25. Array menjadi [34, 25, 64, 12, 22, 11, 90, 0].
// j = 2, bandingkan 64 dan 12. Tukar karena 64 > 12. Array menjadi [34, 25, 12, 64, 22, 11, 90, 0].
// j = 3, bandingkan 64 dan 22. Tukar karena 64 > 22. Array sekarang adalah [34, 25, 12, 22, 64, 11, 90, 0].
// j = 4, bandingkan 64 dan 11. Tukar karena 64 > 11. Array adalah [34, 25, 12, 22, 11, 64, 90, 0].
// j = 5, bandingkan 64 dan 90. Tidak ada tukar karena 64 < 90.
// j mencapai akhir lingkaran dalam tanpa pertukaran lebih lanjut. bendera ditukar tetap benar.
// Iterasi 2:

// Lingkup luar: i = 1
// Lingkup dalam:
// j = 0, bandingkan 34 dan 25. Tukar karena 34 > 25. Array adalah [25, 34, 12, 22, 11, 64, 90, 0].
// j = 1, bandingkan 34 dan 12. Tukar karena 34 > 12. Array menjadi [25, 12, 34, 22, 11, 64, 90, 0].
// j = 2, bandingkan 34 dan 22. Tukar karena 34 > 22. Array menjadi [25, 12, 22, 34, 11, 64, 90, 0].
// j = 3, bandingkan 34 dan 11. Tukar karena 34 > 11. Array adalah [25, 12, 22, 11, 34, 64, 90, 0].
// j = 4, bandingkan 34 dan 64. Tidak ada tukar karena 34 < 64.
// j mencapai akhir lingkaran dalam tanpa pertukaran lebih lanjut. bendera ditukar tetap benar.
// Iterasi 3:

// Lingkup luar: i = 2
// Lingkup dalam:
// j = 0, bandingkan 25 dan 12. Tukar karena 25 > 12. Array adalah [12, 25, 22, 11, 34, 64, 90, 0].
// j = 1, bandingkan 25 dan 22. Tukar karena 25 > 22. Array menjadi [12, 22, 25, 11, 34, 64, 90, 0].
// j = 2, bandingkan 25 dan 11. Tukar karena 25 > 11. Array menjadi [12, 22, 11, 25, 34, 64, 90, 0].
// j = 3, bandingkan 25 dan 34. Tidak ada tukar karena 25 < 34.
// j mencapai akhir lingkaran dalam tanpa pertukaran lebih lanjut. **bendera di