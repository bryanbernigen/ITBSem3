'''
Kode baudot merupakan kode dengan panjang 5 bit sehingga
Penulis gantikan dengan integer 0-31 yakni 00000 - 11111
'''
# inisialisasi
pesan = [0 for i in range(32)]
kunci = 0
hasil = [0 for i in range(32)]

# membuat pesan menjadi 0-31
for i in range(31):
    pesan[i+1] += i+1

# melakukan XOR dengan key 0-31
for i in range(32):
    for j in range(32):
        if(j == 0 or j == 2 or j == 8 or j == 27 or j == 31):
            pass
        else:
            hasil[pesan[j] ^ kunci] += 1
    kunci += 1

print("hasil:")
for i in range(4):
    for j in range(8):
        print(hasil[j+8*i], end=" ")
    print("")
