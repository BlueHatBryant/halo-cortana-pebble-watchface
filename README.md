# Halo Cortana Watchface

A minimalist Pebble watchface featuring Chief and Cortana from the Halo universe with clean time display in signature cyan color.

## Features

- **Clean Design**: Time-only display with no clutter
- **Halo Theme**: Cortana background with cyan text matching her signature color
- **12-Hour Format**: Always displays time in 12-hour format (e.g., 3:45)
- **Universal Compatibility**: Works on all Pebble models (Aplite, Basalt, Chalk, Diorite, Emery)
- **Low Memory Usage**: Only 1065 bytes RAM footprint

## Screenshots

*Add screenshots of your watchface on different Pebble models here*

## Installation

### Method 1: Direct Install (Recommended)
1. Download `halo-cortana.pbw` from the releases
2. Transfer the file to your phone
3. Open with the Pebble app to install

### Method 2: Sideload via Computer
1. Connect your Pebble to your computer
2. Use Pebble SDK: `pebble install --phone [phone_ip]`

## Compatibility

| Pebble Model | Status | Screen Size |
|--------------|--------|-------------|
| Pebble (Aplite) | ✅ Supported | 144×168 B&W |
| Pebble Time (Basalt) | ✅ Supported | 144×168 Color |
| Pebble Time Round (Chalk) | ✅ Supported | 180×180 Color |
| Pebble 2 (Diorite) | ✅ Supported | 144×168 B&W |
| Pebble Time 2 (Emery) | ✅ Supported | 200×228 Color |

## Development

### Building from Source

**Prerequisites:**
- Pebble SDK 3.x
- Python 2.7

**Build Steps:**
```bash
git clone [your-repo-url]
cd halo-cortana
pebble build
```

**Install to Device:**
```bash
pebble install --emulator basalt  # For emulator
pebble install --phone [phone_ip] # For real device
```

### Project Structure
```
halo-cortana/
├── src/c/halo-cortana.c          # Main watchface code
├── resources/images/              # Cortana background images
│   └── cortana_144x168v6.png     # Active background
├── package.json                  # Pebble project config
└── build/halo-cortana.pbw        # Compiled watchface
```

## Technical Details

- **Language**: C
- **SDK Version**: Pebble SDK 3.x
- **Memory Usage**: 1065 bytes RAM
- **Update Frequency**: Every minute
- **Font**: Bitham 42 Bold
- **Text Color**: Cyan (#00FFFF)

## Credits

- **Developer**: MakeAwesomeHappen
- **Cortana Character**: Microsoft/343 Industries (Halo franchise)
- **Platform**: Pebble Technology

## License

This project is for educational and personal use. Halo and Cortana are trademarks of Microsoft Corporation.

## Support

For issues or questions:
- Open an issue on GitHub
- Post in r/pebble subreddit
- Join the Rebble Discord community

## Changelog

### v1.0.0
- Initial release
- Clean time-only display
- Cortana background with cyan text
- Support for all Pebble models