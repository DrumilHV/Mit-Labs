# Generated by Django 5.0.4 on 2024-04-24 07:37

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ("app", "0001_initial"),
    ]

    operations = [
        migrations.AlterField(
            model_name="human", name="phone", field=models.CharField(max_length=100),
        ),
    ]
