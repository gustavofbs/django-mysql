# Generated by Django 5.0.6 on 2024-05-30 23:11

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('rastrobotDjango', '0005_rename_sensor_direito_esp32data_sensordireito_and_more'),
    ]

    operations = [
        migrations.RenameField(
            model_name='esp32data',
            old_name='sensorDireito',
            new_name='sensor_direito',
        ),
        migrations.RenameField(
            model_name='esp32data',
            old_name='sensorEsquerdo',
            new_name='sensor_esquerdo',
        ),
    ]