# Breadth-Depth-First-Search  Graph Applications
Algorithm Analysis



Konu: Graf Uygulamaları

Problem: Bu ödevde bir sosyal ağda influencer olan kişileri tespit eden bir algoritma geliştirmeniz istenmektedir. Algoritmanızı tasarlarken gereken yerlerde DFS ve/veya BFS algoritmalarını kullanınız.

İşlem adımları: Bir sosyal ağda influencer kişileri tespit etmenin farklı yöntemleri vardır. Bu ödevde bu yöntemlerden ikisi kullanılacaktır. Verilen yönlü grafta düğümler kişilerin ad ve soyad bilgilerini, yönlü bağlantılar ise kişinin takip ettiği kişilere olan bağlantıları göstermektedir. Bu graf üzerinde yapılacak işlemlerin adımları aşağıdaki gibidir: 
    1. Bir grafta hangi düğümlerin influencer kişilere ait olduğunu bulurken her düğüm için hesaplama yapmak gerekir. Fakat özellikle büyük bir ağda, az takipçisi olan kişiler için de işlem yapmak gereksiz zaman kaybı olacaktır. Influencer olma potansiyeli olmayan düğümleri elemek için, aşağıdaki işlemi yapan fonksiyonu yazınız: 
Düğümlerin in-degree (kendisine doğru olan bağlantılar) değerini hesaplayarak, in-degree değeri verilen bir M değerinden küçük olan düğümleri eleyiniz. Eleme işleminden sonra in-degree değeri M’in altına düşen düğümleri de eleyiniz. Bu işlemi in-degree değeri M’in altında olan düğüm kalmayana kadar tekrarlayınız.
    2.  1. şıkta elenmeyen düğümler için bir düğüme doğrudan ve dolaylı yoldan gelen toplam bağlantı sayısını hesaplayan fonksiyonu yazınız. Örneğin aşağıdaki örnekte 3 numaralı düğüme 4 ve 5 numaralı düğümlerden gelen doğrudan bağlantılar dışında, 0-5-3 ve 0-6-4-3 bağlantılarından ötürü 0, 4, 5 ve 6 düğümlerinden gelen toplam 4 bağlantı vardır. 

    3. Yukarıda 1. şıkta hesapladığınız düğümler içinde, X>M olmak üzere, in-degree değeri bir X sayısından büyük-eşit olan ve 2. şıkta hesapladığınız toplam gelen bağlantı sayısı bir Y değerinden büyük-eşit olan düğümler influencer kişilere aittir. Bu kişilerin bilgilerini yazdırınız. 


        b. Uygulama bölümünde socialNET.txt dosyasını giriş olarak alıp, aşağıdaki durumlar için elde ettiğiniz sonuçlara ait program çıktılarınızın ekran görüntülerini ekleyerek gösteriniz. Programınız kullanıcının isteğine göre normal ve detay modu olmak üzere iki durum için çıktı vermelidir:
            i. Normal modda çalıştırma: Programınız normal modda çalıştırıldığında verilen  M, X ve Y değerleri için influencer kişilerin bilgilerini ekrana yazdırız.  

            ii. Detay modda çalıştırma: Programınız detay modda çalıştırıldığında verilen giriş dosyası için aşağıdaki bilgileri ekrana yazdırınız: 
                1. Graftaki bütün düğümlerin başlangıç durumunda in-degree değerleri
                2. Verilen M değeri için elenmeyen düğümlerin in-degree değerleri ve bu düğümlerdeki kişilerin ad-soyad bilgileri 
                3. Verilen X ve Y değerleri için influencer olduğu belirlenen kişilerin ad-soyad bilgilerini, bu düğümlerin in-degree değerlerini, doğrudan ve dolaylı toplam bağlantı sayısını ekrana yazdırınız.
        c. Sonuç bölümünde yazdığınız fonksiyonların karmaşıklarını ayrı ayrı hesaplayarak veriniz. 
