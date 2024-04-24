from django.db import models

# Create your models here.

class works(models.Model):
    name = models.CharField(max_length=100)
    company = models.CharField(max_length=100)
    sal = models.PositiveIntegerField()
    class Meta:
        ordering = ('name',)

class lives(models.Model):
    name = models.CharField(max_length=100)
    street =models.CharField(max_length=100)
    state = models.CharField(max_length=100)

