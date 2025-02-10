# GET Package Manager

GET is a simple package manager wrapper written in C++ that provides an easier way to interact with `apt-get` on Debian-based systems. It supports both English and Vietnamese.

## Features

- List available and installed packages
- Install and remove packages
- Search for packages
- Update package lists
- Get package information
- Upgrade all packages
- Remove unnecessary packages
- Clean package cache
- Hold and unhold packages
- Support for language switching (English & Vietnamese)

## Installation

```sh
make
sudo mv get /usr/local/bin/
```

## Usage

### General Syntax

```sh
get <command> [arguments]
```

### Available Commands

| Command          | Description (English)         | Description (Vietnamese)        |
| ---------------- | ----------------------------- | ------------------------------- |
| `list`           | List all available packages   | Liệt kê các gói có sẵn          |
| `list-installed` | List installed packages       | Liệt kê các gói đã cài đặt      |
| `install <pkg>`  | Install a package             | Cài đặt một gói                 |
| `remove <pkg>`   | Remove a package              | Gỡ bỏ một gói                   |
| `search <pkg>`   | Search for a package          | Tìm kiếm một gói                |
| `update`         | Update package lists          | Cập nhật danh sách gói          |
| `info <pkg>`     | Get package information       | Lấy thông tin gói               |
| `upgrade`        | Upgrade all packages          | Nâng cấp tất cả gói             |
| `autoremove`     | Remove unnecessary packages   | Xóa các gói không cần thiết     |
| `clean`          | Clean package cache           | Dọn dẹp cache gói               |
| `hold <pkg>`     | Hold a package from updating  | Giữ một gói không nâng cấp      |
| `unhold <pkg>`   | Unhold a package              | Bỏ giữ một gói                  |
| `set lang Vni`   | Switch language to Vietnamese | Chuyển ngôn ngữ sang tiếng Việt |
| `set lang Eng`   | Switch language to English    | Chuyển ngôn ngữ sang tiếng Anh  |
| `credits`        | Show project credits          | Hiển thị thông tin tác giả      |

### Example Usage

```sh
get list
get install nano
get remove vim
get search curl
get update
get upgrade
get autoremove
get clean
get hold firefox
get unhold firefox
get set lang Vni
get credits
```

## Language Persistence

The selected language setting is stored in `/tmp/get_config.txt`, ensuring that it remains persistent across runs.

## Credits

- **Author:** ItsNvrrrrrrrrrr
- **Written in:** C++
- **Supported by:** GitHub Copilot
- **Uses:** Advanced Packing Tool (APT)

