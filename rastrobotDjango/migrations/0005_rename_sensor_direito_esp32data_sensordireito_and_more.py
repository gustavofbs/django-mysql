# Generated by Django 5.0.6 on 2024-05-30 23:09

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('rastrobotDjango', '0004_rename_sensordireito_esp32data_sensor_direito_and_more'),
    ]

    operations = [
        migrations.RenameField(
            model_name='esp32data',
            old_name='sensor_direito',
            new_name='sensorDireito',
        ),
        migrations.RenameField(
            model_name='esp32data',
            old_name='sensore_esquerdo',
            new_name='sensorEsquerdo',
        ),
    ]