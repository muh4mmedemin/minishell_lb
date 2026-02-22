# 📚 minishell_lb

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" />
  <img src="https://img.shields.io/badge/School-42%20Istanbul-darkblue?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Type-Static%20Library-orange?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Output-minishell__lb.a-brightgreen?style=for-the-badge" />
</p>

---

## 🇬🇧 English

### 📖 About

**minishell_lb** is a reusable **static C library** designed to support the **minishell** project at 42 School. It provides essential utilities for environment variable management, user information retrieval, string manipulation, and a colorful readline-style prompt generation — all in one compact, Norminette-compliant package.

### ✨ Features

| Module | Description |
|--------|------------|
| **Environment List** | Create, search, update, and convert `envp` into a linked list (`t_envp_list`) |
| **User Info** | Retrieve the current username, PC hostname, and working directory from the system |
| **Prompt Generator** | Build a colorful `user@hostname:~/path$` prompt string compatible with `readline` |
| **String Utilities** | Compare strings, calculate array lengths, clear allocated arrays, strip unwanted characters |

### 🏗️ Project Structure

```
minishell_lb/
├── Makefile
├── includes/
│   └── minishell_lb.h           # Main header file
├── create_envp_list.c           # Create envp linked list & update values
├── create_envp_list_2.c         # Parse key names from envp array
├── envp_list_utility.c          # Search, size, convert & print envp list
├── envp_list_funcs.c            # Find node address by id_name
├── get_user_value.c             # Get username, parse /proc & /etc/passwd, prompt builder
├── get_user_value_2.c           # Get PC hostname & current working directory
└── string_edit.c                # ft_strcmp, clear_arr, ft_arrlen, cut_wrong_chracter
```

### 📦 API Reference

#### Environment List Functions

```c
// Create a linked list from envp array
t_envp_list  *create_envp_list(char **envp);

// Find a value by its key name
char         *find_value_on_envp(t_envp_list **list, char *value_id_name);

// Find a key name in the list
char         *find_id_name_on_envp(t_envp_list **list, char *value_id_name);

// Find node address by id_name
t_envp_list  *find_node_address(t_envp_list **source_list, char *id_name);

// Update the value of an existing key
void          update_envp_value(t_envp_list **list, char *id_name, char *new_value);

// Convert linked list back to char** array
char        **envp_list_to_char_arr(t_envp_list *envp_list);

// Get the size of the envp linked list
int           size_of_envp_list(t_envp_list *envp_list);

// Print all envp entries to stdout
void          print_envp_linked_list(t_envp_list *envp_list);
```

#### User & Prompt Functions

```c
// Get the current system username (reads /proc/self/status & /etc/passwd)
char  *get_user_name(void);

// Get the PC hostname (reads /etc/hostname)
char  *get_pc_name(void);

// Get the current working directory (with color)
char  *get_location(void);

// Build a full colorful readline prompt: user@hostname:~/path$
char  *rl_header(t_envp_list **list, char **envp);
```

#### String Utility Functions

```c
// Compare two strings (like strcmp)
int    ft_strcmp(const char *s1, const char *s2);

// Get the length of a NULL-terminated string array
int    ft_arrlen(const char **arr);

// Free a NULL-terminated string array
void   clear_arr(char ***input);

// Strip newline/carriage return characters from a string
char  *cut_wrong_chracter(const char *s1);
```

### 🔗 Dependencies

This library depends on the following 42 libraries (must be available in your include path):

| Library | Header |
|---------|--------|
| **libft** | `<libft.h>` |
| **gb** (Garbage Collector) | `<gb.h>` |
| **get_next_line** | `<get_next_line.h>` |

### ⚙️ Installation & Usage

#### Build the Library

```bash
# Clone the repository
git clone https://github.com/muh4mmedemin/minishell_lb.git
cd minishell_lb

# Build the static library
make
```

This produces **`minishell_lb.a`** — a static archive ready to link into your minishell project.

#### Link into Your Project

```bash
cc -Wall -Wextra -Werror -o minishell your_files.c -L. -lminishell_lb -Iincludes
```

#### Makefile Commands

| Command       | Description                                |
|--------------|--------------------------------------------|
| `make`       | Build the static library `minishell_lb.a`  |
| `make clean` | Remove object files                        |
| `make fclean`| Remove object files and the library archive|
| `make re`    | Rebuild from scratch                       |

### 💡 Usage Example

```c
#include <minishell_lb.h>

int main(int ac, char **av, char **envp)
{
    t_envp_list *env_list;
    char        *prompt;
    char        *home;

    // Create environment linked list
    env_list = create_envp_list(envp);

    // Find the HOME variable
    home = find_value_on_envp(&env_list, "HOME");

    // Generate a colorful prompt
    prompt = rl_header(&env_list, envp);

    // Use with readline...
    return (0);
}
```

### 🛠️ Technologies

- **C** — Programming language
- **Static Library** (`.a`) — Compiled with `ar -rcs`
- **42 Norm** — Fully Norminette compliant
- **Linked List** — Efficient envp data structure

---

## 🇹🇷 Türkçe

### 📖 Hakkında

**minishell_lb**, 42 Okulu'ndaki **minishell** projesini desteklemek için tasarlanmış yeniden kullanılabilir bir **statik C kütüphanesidir**. Ortam değişkeni yönetimi, kullanıcı bilgisi alma, string manipülasyonu ve renkli readline tarzı prompt oluşturma gibi temel yardımcı araçları tek bir kompakt, Norminette uyumlu pakette sunar.

### ✨ Özellikler

| Modül | Açıklama |
|-------|----------|
| **Ortam Değişkenleri Listesi** | `envp` dizisini bağlı listeye (`t_envp_list`) dönüştürme, arama, güncelleme ve geri çevirme |
| **Kullanıcı Bilgisi** | Sistemden mevcut kullanıcı adı, PC hostname ve çalışma dizinini alma |
| **Prompt Oluşturucu** | `readline` uyumlu renkli `kullanıcı@hostname:~/yol$` prompt stringi oluşturma |
| **String Araçları** | String karşılaştırma, dizi uzunluğu hesaplama, bellek temizleme, istenmeyen karakter kaldırma |

### 🏗️ Proje Yapısı

```
minishell_lb/
├── Makefile
├── includes/
│   └── minishell_lb.h           # Ana başlık dosyası
├── create_envp_list.c           # Envp bağlı listesi oluşturma ve değer güncelleme
├── create_envp_list_2.c         # Envp dizisinden anahtar adlarını ayrıştırma
├── envp_list_utility.c          # Envp listesinde arama, boyut, dönüştürme ve yazdırma
├── envp_list_funcs.c            # id_name'e göre düğüm adresi bulma
├── get_user_value.c             # Kullanıcı adı alma, /proc & /etc/passwd okuma, prompt oluşturucu
├── get_user_value_2.c           # PC hostname ve mevcut çalışma dizini alma
└── string_edit.c                # ft_strcmp, clear_arr, ft_arrlen, cut_wrong_chracter
```

### 📦 API Referansı

#### Ortam Değişkenleri Listesi Fonksiyonları

| Fonksiyon | Açıklama |
|-----------|----------|
| `create_envp_list(char **envp)` | Envp dizisinden bağlı liste oluşturur |
| `find_value_on_envp(list, id_name)` | Anahtar adına göre değer bulur |
| `find_id_name_on_envp(list, id_name)` | Listede anahtar adını arar |
| `find_node_address(list, id_name)` | id_name'e göre düğüm adresini döndürür |
| `update_envp_value(list, id, new_val)` | Mevcut bir anahtarın değerini günceller |
| `envp_list_to_char_arr(list)` | Bağlı listeyi `char**` dizisine çevirir |
| `size_of_envp_list(list)` | Envp bağlı listesinin boyutunu döndürür |
| `print_envp_linked_list(list)` | Tüm envp girdilerini stdout'a yazdırır |

#### Kullanıcı & Prompt Fonksiyonları

| Fonksiyon | Açıklama |
|-----------|----------|
| `get_user_name()` | Sistem kullanıcı adını döndürür (`/proc/self/status` & `/etc/passwd` okur) |
| `get_pc_name()` | PC hostname'ini döndürür (`/etc/hostname` okur) |
| `get_location()` | Mevcut çalışma dizinini renkli olarak döndürür |
| `rl_header(list, envp)` | Renkli tam readline promptu oluşturur |

#### String Yardımcı Fonksiyonları

| Fonksiyon | Açıklama |
|-----------|----------|
| `ft_strcmp(s1, s2)` | İki stringi karşılaştırır |
| `ft_arrlen(arr)` | NULL ile sonlanan string dizisinin uzunluğunu hesaplar |
| `clear_arr(input)` | NULL ile sonlanan string dizisini serbest bırakır |
| `cut_wrong_chracter(s1)` | Stringden newline/carriage return karakterlerini temizler |

### 🔗 Bağımlılıklar

Bu kütüphane aşağıdaki 42 kütüphanelerine bağlıdır (include path'inizde mevcut olmalıdır):

| Kütüphane | Başlık Dosyası |
|-----------|---------------|
| **libft** | `<libft.h>` |
| **gb** (Çöp Toplayıcı) | `<gb.h>` |
| **get_next_line** | `<get_next_line.h>` |

### ⚙️ Kurulum ve Kullanım

#### Kütüphaneyi Derleme

```bash
# Depoyu klonlayın
git clone https://github.com/muh4mmedemin/minishell_lb.git
cd minishell_lb

# Statik kütüphaneyi derleyin
make
```

Bu komut **`minishell_lb.a`** statik arşivini oluşturur — minishell projenize bağlamaya hazır.

#### Projenize Bağlama

```bash
cc -Wall -Wextra -Werror -o minishell dosyalarınız.c -L. -lminishell_lb -Iincludes
```

#### Makefile Komutları

| Komut         | Açıklama                                         |
|--------------|--------------------------------------------------|
| `make`       | Statik kütüphane `minishell_lb.a` dosyasını derle |
| `make clean` | Obje dosyalarını sil                              |
| `make fclean`| Obje dosyalarını ve kütüphane arşivini sil        |
| `make re`    | Sıfırdan yeniden derle                            |

### 💡 Kullanım Örneği

```c
#include <minishell_lb.h>

int main(int ac, char **av, char **envp)
{
    t_envp_list *env_list;
    char        *prompt;
    char        *home;

    // Ortam değişkenleri bağlı listesini oluştur
    env_list = create_envp_list(envp);

    // HOME değişkenini bul
    home = find_value_on_envp(&env_list, "HOME");

    // Renkli prompt oluştur
    prompt = rl_header(&env_list, envp);

    // readline ile kullan...
    return (0);
}
```

### 🛠️ Kullanılan Teknolojiler

- **C** — Programlama dili
- **Statik Kütüphane** (`.a`) — `ar -rcs` ile derlenir
- **42 Norm** — Tamamen Norminette uyumlu
- **Bağlı Liste** — Verimli envp veri yapısı

---

## 👥 Authors / Yazarlar

- **muayna** — 42 Istanbul — [@muh4mmedemin](https://github.com/muh4mmedemin)
- **yademirk** — 42 Istanbul

---

## 📝 License / Lisans

This project is part of the 42 School curriculum.

Bu proje 42 Okulu müfredatının bir parçasıdır.
