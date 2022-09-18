giriiş
Lütfen aşağıdaki kurallara uyunuz: - Değerlendirme süreci

boyunca kibar, nazik, saygılı ve yapıcı olun.
Toplumun refahı buna bağlıdır.

- Çalışmaları değerlendirilen öğrenci veya grupla
projelerindeki olası işlev bozukluklarını belirleyin.
Belirlenmiş olabilecek sorunları tartışmak ve tartışmak için zaman ayırın . - Meslektaşlarınızın projenin talimatlarını ve işlevlerinin kapsamını

nasıl anlamış olabileceği konusunda bazı farklılıklar olabileceğini göz önünde bulundurmalısınız . Her zaman açık fikirli olun ve onları mümkün olduğunca dürüst bir şekilde değerlendirin. Pedagoji, ancak ve ancak akran değerlendirmesi ciddi bir şekilde yapıldığında faydalıdır.




Yönergeler

- Yalnızca değerlendirilen öğrenci veya grubun Git deposunda döndürülen çalışmaya not verin .

- Git deposunun öğrenciye/öğrencilere ait olduğunu iki kez kontrol edin.
Projenin beklenen olduğundan emin olun .
Ayrıca, boş bir klasörde 'git klonunun' kullanıldığını kontrol edin . - Sizi kandırmak ve resmi arşivin içeriği olmayan bir şeyi değerlendirmenizi

sağlamak için hiçbir kötü niyetli takma adın kullanılmadığını dikkatlice kontrol edin . - Sürprizlerden kaçınmak için ve varsa , not vermeyi kolaylaştırmak için kullanılan komut dosyalarını (test veya otomasyon komut dosyaları) birlikte inceleyin. - Değerlendireceğiniz ödevi tamamlamadıysanız, değerlendirme sürecine başlamadan önce konunun tamamını okumanız gerekmektedir.









- Boş bir depoyu, çalışmayan bir programı, bir Norm hatasını, hileyi vb. bildirmek için mevcut bayrakları kullanın .
Bu durumlarda değerlendirme süreci sona erer ve final notu 0,
kopya durumunda ise -42 olur. Ancak kopya dışında, öğrencinin
teslim ettiği çalışmayı birlikte gözden geçirmesi
ve gelecekte tekrarlanmaması gereken hataları tespit etmesi şiddetle tavsiye edilir.

- Ayrıca bellek sızıntısı olmadığını da doğrulamalısınız. Yığın üzerinde ayrılan herhangi bir bellek
, yürütme sona ermeden önce uygun şekilde serbest bırakılmalıdır. Sızıntılar, valgrind veya e_fence gibi
bilgisayarda bulunan farklı araçlardan herhangi birini kullanmanıza izin verilir .
Bellek sızıntısı olması durumunda,
uygun bayrak.
ekler
 konu.pdf  checker_Mac  checker_linux
Zorunlu kısım
Hatırlatma : Savunma süresince, programın herhangi bir segfault veya diğer beklenmedik, erken, kontrolsüz veya beklenmedik bir şekilde sonlandırılmasının olmadığını, aksi takdirde final notunun 0 olduğunu unutmayın. Uygun bayrağı kullanın. Bu kural tüm savunma boyunca aktiftir.

Bellek sızıntıları

Savunma boyunca, herhangi bir anormalliği tespit etmek ve tahsis edilen belleğin uygun şekilde serbest bırakıldığından emin olmak
için push_swap tarafından kullanılan bellek miktarına (örneğin üst komutu kullanarak) dikkat edin . Bir (veya daha fazla) bellek sızıntısı varsa, son not 0'dır.



Hata yönetimi

Bu bölümde push_swap'ın hata yönetimini değerlendireceğiz. En az biri başarısız olursa, bu bölüm
için puan verilmeyecektir .
Bir sonrakine geç.

- Push_swap'ı sayısal olmayan parametrelerle çalıştırın. Program
"Hata" göstermelidir.

- Push_swap'ı yinelenen bir sayısal parametreyle çalıştırın. Program
"Hata" göstermelidir.

- push_swap'ı yalnızca
MAXINT'ten büyük bir tane dahil olmak üzere sayısal parametrelerle çalıştırın. Program "Hata" göstermelidir.

- push_swap'ı herhangi bir parametre olmadan çalıştırın. Program
hiçbir şey göstermemeli ve istemi geri vermemelidir.
Push_swap - Kimlik testi


Bu bölümde, zaten sıralanmış bir liste verildiğinde push_swap'ın davranışını değerlendireceğiz . Aşağıdaki 3
testi gerçekleştirin.
En az biri başarısız olursa, bu bölüm için puan verilmeyecektir . Bir sonrakine geç.

- Aşağıdaki "$>./push_swap 42" komutunu çalıştırın. Program
hiçbir şey göstermemelidir (0 talimat).

- Aşağıdaki "$>./push_swap 0 1 2 3" komutunu çalıştırın. Program
hiçbir şey göstermemelidir (0 talimat).

- Aşağıdaki "$>./push_swap 0 1 2 3 4 5 6 7 8
9" komutunu çalıştırın. Program hiçbir şey göstermemelidir (0 talimat).
Push_swap - Basit sürüm


Aşağıdaki test başarısız olursa, bu bölüm için puan verilmeyecektir . Bir sonrakine geç. Eklerde verilen denetleyici ikili dosyasını kullanın
.

- "$>ARG="2 1 0"; ./push_swap $ARG | ./checker_OS $ARG" komutunu çalıştırın.
Kontrol programının "OK" gösterdiğini ve
push_swap'tan gelen talimat listesinin boyutunun 2 VEYA 3 olduğunu kontrol edin.
Aksi takdirde test başarısız olur.
Başka bir basit versiyon

Aşağıdaki 2 testi gerçekleştirin. En az biri başarısız olursa,
bu bölüm için puan verilmeyecektir. Bir sonrakine geç. Eklerde verilen denetleyici
ikili dosyasını kullanın.

- "$>ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_OS $ARG" komutunu çalıştırın.
Kontrol programının "OK"
yazıp göstermediğini ve push_swap'tan gelen talimat listesinin boyutunun
12'den fazla olmadığını kontrol edin. Talimat listesinin boyutu 8 ise Kudos

- "$>ARG="<5 rasgele çalıştırın . değerler>"; ./push_swap $ARG | ./checker_OS
$ARG" ve yer tutucuyu 5 rastgele geçerli değerle değiştirin.
Kontrol programının "Tamam" gösterdiğini kontrol edin

12'den fazla. Aksi takdirde bu test başarısız olur. Programın yalnızca bu ölçekte yer alan testte doğru yanıt verecek şekilde
geliştirilmediğini özellikle kontrol etmeniz gerekecektir .
Doğrulamadan önce
bu testi birkaç
permütasyonla birkaç kez tekrarlamalısınız.
Push_swap - Orta sürüm


Aşağıdaki test başarısız olursa, bu bölüm için puan verilmeyecektir . Bir sonrakine geç. Bir sonrakine geç. Eklerde verilen denetleyici
ikili dosyasını kullanın.

- "$>ARG="<100 rastgele değer>"; ./push_swap $ARG |
./checker_OS $ARG" komutunu çalıştırın ve yer tutucuyu 100 rastgele
geçerli değerle değiştirin. Kontrol programının "OK"
gösterdiğini ve talimat listesinin boyutunu kontrol edin.
Puan verin:
- 700'den az: 5
- 900'den az: 4
- 1100'den az: 3
- 1300'den az: 2
- 1500'den az: 1
Programın aşağıdakilere göre geliştirilmediğini özellikle kontrol etmeniz gerekecek.
sadece bu ölçekte yer alan testte doğru cevap verin.
Doğrulamadan önce bu testi birkaç
permütasyonla birkaç kez tekrarlamalısınız.
0'dan (başarısız) 5'e (mükemmel) kadar derecelendirin

Push_swap - Gelişmiş sürüm


Aşağıdaki test başarısız olursa, bu bölüm için puan verilmeyecektir . Bir sonrakine geç. Bir sonrakine geç. Eklerde verilen denetleyici
ikili dosyasını kullanın.

- "$>ARG="<500 rastgele değer>"; ./push_swap $ARG |
./checker_OS $ARG" komutunu çalıştırın ve yer tutucuyu 500 rastgele
geçerli değerle değiştirin (Biri
boşuna John/Jane Script olarak adlandırılmaz). Kontrol programında "Tamam" görüntülendiğini ve
talimat listesinin boyutunun
- 5500'den az: 5
- 7000'den az: 4
- 8500'den az: 3
- 10000'den az: 2
- 11500'den az: 1
Siz' Programın özel olarak geliştirilmediğini kontrol etmem gerekecek.
sadece bu ölçekte yer alan testte doğru cevap verin.
Doğrulamadan önce bu testi birkaç
permütasyonla birkaç kez tekrarlamalısınız.
0'dan (başarısız) 5'e (mükemmel) kadar derecelendirin

Bonus
Hatırlatma : Savunma süresince, programın herhangi bir segfault veya diğer beklenmedik, erken, kontrolsüz veya beklenmedik bir şekilde sonlandırılmasının olmadığını, aksi takdirde final notunun 0 olduğunu unutmayın. Uygun bayrağı kullanın. Bu kural tüm savunma boyunca etkindir. Bonuslarınıza ancak ve ancak zorunlu bölümünüz MÜKEMMEL ise bakacağız. Bu, zorunlu kısmı baştan sona tamamlamanız gerektiği ve hatalı veya hatalı kullanım durumlarında bile hata yönetiminizin kusursuz olması gerektiği anlamına gelir. Bu nedenle, zorunlu kısım bu savunma sırasında tüm puanları almadıysa, bonuslar tamamen GÖZDEN GEÇİRİLECEKTİR.

Kontrol programı - Hata yönetimi

Bu bölümde, denetleyicinin hata yönetimini değerlendireceğiz. En az biri başarısız olursa, bu bölüm
için puan verilmeyecektir .
Bir sonrakine geç.

- Sayısal olmayan parametrelerle denetleyiciyi çalıştırın. Program
"Hata" göstermelidir.

- Denetleyiciyi yinelenen bir sayısal parametreyle çalıştırın. Program
"Hata" göstermelidir. - Denetleyiciyi, MAXINT'ten

daha büyük bir tane dahil olmak üzere yalnızca sayısal parametrelerle çalıştırın .
Program "Hata" göstermelidir.

- Denetleyiciyi herhangi bir parametre olmadan çalıştırın. Program
hiçbir şey göstermemeli ve istemi geri vermemelidir.

- Checker'ı geçerli parametrelerle çalıştırın
ve talimat aşamasında olmayan bir eylem yazın. Program
"

- Checker'ı geçerli parametrelerle çalıştırın ve talimat aşamasında
eylemden önce ve/veya sonra bir veya birkaç boşlukla bir eylem yazın.
Program "Hata" göstermelidir.
Kontrol programı - Yanlış testler

Bu bölümde, denetleyicinin
listeyi sıralamayan bir talimat listesini yönetme yeteneğini değerlendireceğiz. Aşağıdaki
2 testi gerçekleştirin. En az biri başarısız olursa,
bu bölüm için puan verilmeyecektir. Bir sonrakine geç. Giriş aşamasında

okumayı durdurmak için CTRL+D'ye basmayı unutmayın . - Checker'ı "$>./checker 0 9 1 8 2 7 3 6 4 5" komutuyla çalıştırın ve ardından aşağıdaki geçerli eylem listesini "[sa, pb, rrr]" yazın. Denetleyici "KO" göstermelidir. - Seçtiğiniz parametre olarak geçerli bir liste ile denetleyiciyi çalıştırın ve ardından tamsayıları sıralamayan geçerli bir talimat listesi yazın . Denetleyici "KO" göstermelidir. Zorunda olacaksın









özellikle programın yalnızca
bu ölçekte yer alan testte doğru yanıt verecek şekilde geliştirilmediğini kontrol edin. Doğrulamadan önce
bu testi birkaç
permütasyonla birkaç kez tekrarlamalısınız.
Checker programı - Doğru testler

Bu bölümde, denetleyicinin
listeyi sıralayan bir talimat listesini yönetme yeteneğini değerlendireceğiz. Aşağıdaki
2 testi gerçekleştirin.
En az biri başarısız olursa, bu bölüm için puan verilmeyecektir . Bir sonrakine geç. Komut aşamasında

okumayı durdurmak için CTRL+D'ye basmayı unutmayın . - Checker'ı aşağıdaki "$>./checker 0 1 2" komutu ile çalıştırın ve ardından herhangi bir talimat yazmadan CTRL+D tuşlarına basın. Program "OK" göstermelidir. - Checker'ı "$>./checker 0 9 1 8 2" komutuyla çalıştırın ve ardından aşağıdaki geçerli eylem listesini "[pb, ra, pb, ra, sa, ra, pa, pa]" yazın. Program "OK" göstermelidir.











tamsayıları sıralayan geçerli bir talimat listesi yazın.
Denetleyici "Tamam" göstermelidir. Programın yalnızca bu ölçekte yer alan testte
doğru yanıt verecek şekilde geliştirilmediğini özellikle kontrol etmeniz gerekecektir .
Doğrulamadan önce bu testi
birkaç permütasyonla birkaç kez tekrarlamalısınız
.
