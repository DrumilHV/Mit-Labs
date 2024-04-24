from django.contrib import admin

# Register your models here.
from .models import works, lives
admin.site.register(works)
admin.site.register(lives)