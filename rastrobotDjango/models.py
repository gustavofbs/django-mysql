from django.db import models

class ESP32Data(models.Model):
    sensor_esquerdo = models.CharField(max_length=100)
    sensor_direito = models.CharField(max_length=100)

    def __str__(self):
        return f"{self.sensor_esquerdo}, {self.sensor_direito}"

