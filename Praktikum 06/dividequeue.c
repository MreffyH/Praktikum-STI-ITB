// NIM : 18222103
// Nama : Muhammad Reffy Haykal
// Tanggal : 01/12/2023
// Topik praktikum : queue
// Deskripsi : realisasi dividequeue.h

#include "dividequeue.h"

// Membagi queue.
void divideQueue(Queue *queue, Queue *oddQueue, Queue *evenQueue) 
/* Proses: Membagi isi dari queue ke oddQueue untuk elemen ganjil dan evenQueue untuk elemen genap */
/* I.S. queue mungkin kosong, tabel penampung elemen queue TIDAK penuh */
/* F.S. oddQueue memiliki isi queue elemen ganjil, evenQueue memiliki isi queue elemen genap */
/*
    Contoh input:
    queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
    oddQueue: queue kosong
    evenQueue: queue kosong

    Contoh output:
    queue:  [2,3,4,5,6]
    oddQueue: [3,5]
    evenQueue: [2,4,6]
*/

/*
    Catatan
    - Hati-hati jangan sampai algoritma Anda mengubah hasil akhir dari queueInput juga.
      Elemen di queueInput harus tetap sama setelah algoritma dijalankan.
    Hint
    - Buat queue baru selain queue, oddQueue, dan evenQueue untuk tempat penyimpanan
      queue sementara.
*/
{
  /* Dictionary */
  Queue tempQ;
  int val;
  /* Algorithm */
  CreateQueue(&tempQ);

  while (!isEmpty(*queue))
  {
    dequeue(queue, &val);
    if (val % 2 == 0) {
      enqueue(evenQueue, val);
    } else {
      enqueue(oddQueue, val);
    }
    enqueue(&tempQ, val);
  }
  
  while (!isEmpty(tempQ))
  {
    dequeue(&tempQ, &val);
    enqueue(queue, val);
  }
  
}