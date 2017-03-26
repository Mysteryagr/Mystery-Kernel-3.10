This is 3.10.x MT6580 kernel source ported to be used on Infinix Hot 2 - Android one device.

## Known information
| Subsystem | Driver name | Availability | Working |
|-----------|-------------|--------------|---------|
| LCM driver #1 | `nt35521_dsi_vdo_yushun_cmi_hd720` | Yes | Yes |
| LCM driver #2 | `hx8394d_dsi_vdo_hlt_hsd_hd720` | Yes | No |
| Touch panel | `GT9XX (i2c 1-005D)` | Yes | Yes |
| GPU | `Mali-400 MP` | Yes | Yes |
| Camera #1 | `ov8865_mipi_2lane_raw` | No | No |
| Camera #2 | `syxov8865_mipi_2lane_raw` | No | No |
| Camera #3 | `hi545_2lane_mipi_raw` | Yes | No |
| Camera #4 | `gc2755_mipi_raw` | Yes | No |
| Accelerometer | `BMA222 (i2c 2-0018)` | Yes | ? |
| ALS/PS | `CM36283 (i2c 2-0060)` | Yes | ? |
| Charger | `BQ24158 (i2c 1-006A)` | Yes | ? |
| Flash | `Samsung Q8XSAB` | Yes | Yes |
| Lens #1 | `DW9714AF` | Yes | ? |
| Lens #2 | `FM50AF` | Yes | ? |
| RAM | `1 GB LPDDR3` | - | - |
| sound | `mtsndcard` | - | - |