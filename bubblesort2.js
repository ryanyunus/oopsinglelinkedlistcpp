function bubbleSort(arr) {
  var len = arr.length;
  for (var i = 0; i < len; i++) {
    for (var j = 0; j < len - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // Swap elemen jika elemen saat ini lebih besar dari elemen berikutnya
        var temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  return arr;
}

// Contoh penggunaan:
var array = [64, 34, 25, 12, 22, 11, 90, 0];
console.log("Array sebelum diurutkan: " + array);
var sortedArray = bubbleSort(array);
console.log("Array setelah diurutkan: " + sortedArray);