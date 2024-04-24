from django.urls import path, include, re_path
from .views import createEmp, retrieveEmp
from . import views
urlpatterns = [
    path('create/',views.createEmp, name='createEmp'),
    path('retrieve/',retrieveEmp, name='retrieveEmp'),
]
