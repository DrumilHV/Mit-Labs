# Generated by Django 5.0.4 on 2024-04-24 05:50

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = []

    operations = [
        migrations.CreateModel(
            name="lives",
            fields=[
                (
                    "id",
                    models.BigAutoField(
                        auto_created=True,
                        primary_key=True,
                        serialize=False,
                        verbose_name="ID",
                    ),
                ),
                ("name", models.CharField(max_length=100)),
                ("street", models.CharField(max_length=100)),
                ("state", models.CharField(max_length=100)),
            ],
        ),
        migrations.CreateModel(
            name="works",
            fields=[
                (
                    "id",
                    models.BigAutoField(
                        auto_created=True,
                        primary_key=True,
                        serialize=False,
                        verbose_name="ID",
                    ),
                ),
                ("name", models.CharField(max_length=100)),
                ("company", models.CharField(max_length=100)),
                ("sal", models.PositiveIntegerField()),
            ],
            options={"ordering": ("name",),},
        ),
    ]