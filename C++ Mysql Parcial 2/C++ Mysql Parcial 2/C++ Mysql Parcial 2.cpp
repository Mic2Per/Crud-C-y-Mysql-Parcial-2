#include <mysql.h>
#include <iostream>
using namespace std;
int q_estado;
int main()
{
	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "qkracha2001", "par", 3306, NULL, 0);
	if (conectar) {
		cout << "conexion exitosa" << endl;
		int op;
		string insert, marca, marca2, consulta, actualizar, eliminar;
		const char* i;
		const char* ii;
		do {
			cout << "1. Menu de la Tabla Marcas" << endl;
			cout << "2. Menu de la Tabla Productos" << endl;
			cout << "Precione 3 para salir" << endl;
			cin >> op;
			cout << "\n";

			switch (op) {
				case 1:
					int op1;
					cout << "1. crear" << endl;
					cout << "2. Leer" << endl;
					cout << "3. Actualizar" << endl;
					cout << "4. Borrar" << endl;
					cin >> op1;
					cout << "\n";

					switch (op1) {
						case 1:
							cout << "Ingrese la marca: ";
							cin >> marca;
							insert = "insert into marcas(marca) values('" + marca + "')";
							i = insert.c_str();
							q_estado = mysql_query(conectar, i);
							if (!q_estado) {
								cout << "Ingreso exitoso" << endl;
								cout << "\n";
							}
							else {
								cout << "Error al ingresar" << endl;
								cout << "\n";
							}

							break;

						case 2:
							consulta = "select * from par.marcas";
							ii = consulta.c_str();
							q_estado = mysql_query(conectar, ii);
							if (!q_estado) {
								resultado = mysql_store_result(conectar);
								while (fila = mysql_fetch_row(resultado)) {
									cout << fila[0] << "," << fila[1] << endl;
									cout << "\n";
								}
							}
							else {
								cout << "Error al consultar" << endl;
								cout << "\n";
							}

							break;

						case 3:
							cout << "Ingrese el id a modificar: ";
							cin >> actualizar;
							cout << "Ingrese la marca: ";
							cin >> marca2;
							insert = "update marcas set marca = '" + marca2 + "' where idMarca= " + actualizar + "";
							i = insert.c_str();
							q_estado = mysql_query(conectar, i);
							if (!q_estado) {
								cout << "Ingreso exitoso" << endl;
								cout << "\n";
							}
							else {
								cout << "Error al ingresar" << endl;
								cout << "\n";
							}

							break;
						
						case 4:
							cout << "Ingrese el id a eliminar: ";
							cin >> eliminar;
							insert = "delete from marcas where idMarca=" + eliminar + "";
							i = insert.c_str();
							q_estado = mysql_query(conectar, i);
							if (!q_estado) {
								cout << "Registro eliminado" << endl;
								cout << "\n";
							}
							else {
								cout << "Error al ingresar" << endl;
								cout << "\n";
							}
							break;

					}

					break;

				case 2:
					int op2;
					string insert2, producto, producto2, idmarca, idmarca2, imagen, imagen2, descripcion=" ",  descripcion2=" ", precio1, precio2, precio3, precio4, existencia, existencia2, fecha, fecha2, consulta2, actualizar2, eliminar2;
					const char* e;
					const char* ee;
					cout << "1. crear" << endl;
					cout << "2. Leer" << endl;
					cout << "3. Actualizar" << endl;
					cout << "4. Borrar" << endl;
					cin >> op2;
					cout << "\n";

					switch (op2) {
						case 1:
							cout << "Ingrese el Producto: ";
							cin >> producto;
							cout << "Ingrese el id de la marca: ";
							cin >> idmarca;
							cout << "Ingrese la descripcion: ";
							cin >> descripcion;
							cout << "Ingrese la imagen: ";
							cin >> imagen;
							cout << "Ingrese el precio del costo: ";
							cin >> precio1;
							cout << "Ingrese el precio de venta: ";
							cin >> precio2;
							cout << "Ingrese la existencia: ";
							cin >> existencia;
							cout << "Ingrese la fecha de ingreso: ";
							cin >> fecha;
							insert = "insert into par.productos(producto,IdMarca,Descripcion,Imagen,precio_costo,precio_venta,existencia,Fecha_ingreso) values('" + producto + "','" + idmarca + "','" + descripcion + "','" + imagen + "','" + precio1 + "','" + precio2 + "','" + existencia + "','" + fecha + "');";
							e = insert.c_str();
							q_estado = mysql_query(conectar, e);
							if (!q_estado) {
								cout << "Ingreso exitoso" << endl;
								cout << "\n";
							}
							else {
								cout << "Error al ingresar" << endl;
								cout << "\n";
							}

							break;

						case 2:
							consulta2 = "select * from par.productos";
							ee = consulta2.c_str();
							q_estado = mysql_query(conectar, ee);
							if (!q_estado) {
								resultado = mysql_store_result(conectar);
								while (fila = mysql_fetch_row(resultado)) {
									cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << fila[8] << endl;
									cout << "\n";
								}
							}
							else {
								cout << "Error al consultar" << endl;
								cout << "\n";
							}

							break;

						case 3:
							cout << "Ingrese el id a modificar: ";
							cin >> actualizar2;
							cout << "Ingrese el Producto: ";
							cin >> producto2;
							cout << "Ingrese el id de la marca: ";
							cin >> idmarca2;
							cout << "Ingrese la descripcion: ";
							cin >> descripcion2;
							cout << "Ingrese la imagen: ";
							cin >> imagen2;
							cout << "Ingrese el precio del costo: ";
							cin >> precio3;
							cout << "Ingrese el precio de venta: ";
							cin >> precio4;
							cout << "Ingrese la existencia: ";
							cin >> existencia2;
							cout << "Ingrese la fecha de ingreso: ";
							cin >> fecha2;
							insert = "update productos set producto = '" + producto2 + ",IdMarca = '" + idmarca2 + ",Descripcion = '" + descripcion2 + ",Imagen = '" + imagen2 + ",precio_costo = '" + precio3 + ",precio_venta = '" + precio4 + ",existencia = '" + existencia2 + ",Fecha_ingreso = '" + fecha2 + "' where idProducto= " + actualizar2 + "";
							e = insert.c_str();
							q_estado = mysql_query(conectar, e);
							if (!q_estado) {
								cout << "Ingreso exitoso" << endl;
								cout << "\n";
							}
							else {
								cout << "Error al ingresar" << endl;
								cout << "\n";
							}
							break;

						case 4:
							cout << "Ingrese el id a eliminar: ";
							cin >> eliminar2;
							insert = "delete from productos where idProducto=" + eliminar2 + "";
							e = insert.c_str();
							q_estado = mysql_query(conectar, e);
							if (!q_estado) {
								cout << "Registro eliminado" << endl;
								cout << "\n";
							}
							else {
								cout << "Error al ingresar" << endl;
								cout << "\n";
							}
							break;

					}

					break;
			}
		
		} while (op != 3);
	}
	else {
		cout << "error al conectar" << endl;
	}
	system("pause");
	return 0;
}

/*
#include <mysql.h>
#include <iostream>
using namespace std;
int q_estado;
int main()
{
	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "qkracha2001", "empresa_u", 3306, NULL, 0);
	if (conectar) {
		//cout << "conexion exitosa" << endl;
		int op;
		string insert, producto, producto2, idmarca, idmarca2, descripcion, descripcion2, precio1, precio3, precio2, precio4, existencia, existencia2, fecha, fecha2, consulta, actualizar, eliminar;
		const char* e;
		const char* ee;
		do {

			cout << "1. Tabla Productos" << endl;
			cout << "2. Tabla Marcas" << endl;
			cout << "\n";
			cin >> op;

			switch (op) {
			case 1:
				int op1;
				cout << "1. Crear" << endl;
				cout << "2. Leer" << endl;
				cout << "3. Actualizar" << endl;
				cout << "4. Borrar" << endl;
				cout << "\n";
				cin >> op1;

				switch (op1) {
				case 1:
					resultado = mysql_store_result(conectar);
					fila = mysql_fetch_row(resultado);
					cout << "Ingrese el producto";
					cin >> producto;
					insert = "insert into productos(producto) values('" + producto + "')";
					e = insert.c_str();
					cout << "Ingrese id de la marca";
					cin >> idmarca;
					insert = "insert into productos(idMarca) values('" + idmarca + "')";
					fila = mysql_fetch_row(resultado);
					e = insert.c_str();
					q_estado = mysql_query(conectar, e);


					*cout << "Ingrese el producto";
					cin >> producto;
					insert = "insert into productos(producto) values('" + producto + "')";
					e = insert.c_str();
					q_estado = mysql_query(conectar, e);
					cout << "Ingrese el id de la marca";
					cin >> idmarca;
					insert = "insert into productos(idMarca) values('" + idmarca + "')";
					e = insert.c_str();
					q_estado = mysql_query(conectar, e);
					cout << "Ingrese la descripcion";
					cin >> descripcion;
					insert = "insert into productos(Descripcion) values('" + descripcion + "')";
					e = insert.c_str();
					q_estado = mysql_query(conectar, e);
					cout << "Ingrese el Precio costo";
					cin >> precio1;
					insert = "insert into productos(precio_costo) values('" + precio1 + "')";
					e = insert.c_str();
					q_estado = mysql_query(conectar, e);
					cout << "Ingrese el Precio venta";
					cin >> precio2;
					insert = "insert into productos(precio_venta) values('" + precio2 + "')";
					e = insert.c_str();
					q_estado = mysql_query(conectar, e);
					cout << "Ingrese las existecias";
					cin >> existencia;
					insert = "insert into productos(existencia) values('" + existencia + "')";
					e = insert.c_str();
					q_estado = mysql_query(conectar, e);
					cout << "Ingrese la fecha de ingreso del producto";
					cin >> fecha;
					insert = "insert into productos(fecha_ingreso) values('" + fecha + "')";
					e = insert.c_str();
					q_estado = mysql_query(conectar, e);*



					if (!q_estado) {
						cout << "Ingreso exitoso" << endl;
						cout << "\n";
					}
					else {
						cout << "Error al ingresar" << endl;
						cout << "\n";
					}
					break;

				case 2:
					consulta = "select * from empresa_u.productos";
					ee = consulta.c_str();
					q_estado = mysql_query(conectar, ee);
					if (!q_estado) {
						resultado = mysql_store_result(conectar);
						while (fila = mysql_fetch_row(resultado)) {
							cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;
							cout << "\n";
						}
					}
					else {
						cout << "Error al consultar" << endl;
						cout << "\n";
					}
					break;

				case 3:
					cout << "Ingrese el id a modificar";
					cin >> actualizar;
					cout << "Ingrese el producto";
					cin >> producto2;
					insert = "update productos set producto = '" + producto2 + "' where idMarca= " + actualizar + "";
					e = insert.c_str();
					q_estado = mysql_query(conectar, e);
					cout << "Ingrese el id de la marca";
					cin >> idmarca2;
					insert = "update productos set idMarca = '" + idmarca2 + "' where idMarca= " + actualizar + "";
					e = insert.c_str();
					q_estado = mysql_query(conectar, e);
					cout << "Ingrese descripcion";
					cin >> descripcion2;
					insert = "update productos set Descripcion = '" + descripcion2 + "' where idMarca= " + actualizar + "";
					e = insert.c_str();
					q_estado = mysql_query(conectar, e);
					cout << "Ingrese el precio costo";
					cin >> precio3;
					insert = "update productos set precio_costo = '" + precio3 + "' where idMarca= " + actualizar + "";
					e = insert.c_str();
					q_estado = mysql_query(conectar, e);
					cout << "Ingrese el precio venta";
					cin >> precio4;
					insert = "update productos set precio_venta = '" + precio4 + "' where idMarca= " + actualizar + "";
					e = insert.c_str();
					q_estado = mysql_query(conectar, e);
					cout << "Ingrese las existencias";
					cin >> existencia2;
					insert = "update productos set existencia = '" + existencia2 + "' where idMarca= " + actualizar + "";
					e = insert.c_str();
					q_estado = mysql_query(conectar, e);
					cout << "Ingrese la fecha de entrada del producto";
					cin >> fecha2;
					insert = "update productos set fecha_ingreso = '" + fecha2 + "' where idMarca= " + actualizar + "";
					e = insert.c_str();
					q_estado = mysql_query(conectar, e);
					if (!q_estado) {
						cout << "Ingreso exitoso" << endl;
						cout << "\n";
					}
					else {
						cout << "Error al ingresar" << endl;
						cout << "\n";
					}
					break;

				case 4:

					break;

				}

				break;
			case 2:
				int op2;
				string insert2, marca, marca2, consulta2, actualizar2, eliminar2;
				const char* i;
				const char* ii;
				cout << "1. Crear" << endl;
				cout << "2. Leer" << endl;
				cout << "3. Actualizar" << endl;
				cout << "4. Borrar" << endl;
				cout << "\n";
				cin >> op2;

				switch (op2) {
				case 1:
					cout << "Ingrese la marca";
					cin >> marca;
					insert2 = "insert into marcas(marca) values('" + marca + "')";
					i = insert2.c_str();
					q_estado = mysql_query(conectar, i);
					if (!q_estado) {
						cout << "Ingreso exitoso" << endl;
						cout << "\n";
					}
					else {
						cout << "Error al ingresar" << endl;
						cout << "\n";
					}
					break;

				case 2:
					consulta2 = "select * from empresa_u.marcas";
					ii = consulta2.c_str();
					q_estado = mysql_query(conectar, ii);
					if (!q_estado) {
						resultado = mysql_store_result(conectar);
						while (fila = mysql_fetch_row(resultado)) {
							cout << fila[0] << "," << fila[1] << endl;
							cout << "\n";
						}
					}
					else {
						cout << "Error al consultar" << endl;
						cout << "\n";
					}
					break;

				case 3:
					cout << "Ingrese el id a modificar";
					cin >> actualizar2;
					cout << "Ingrese la marca";
					cin >> marca2;
					insert2 = "update marcas set marca = '" + marca2 + "' where idMarca= " + actualizar2 + "";
					i = insert2.c_str();
					q_estado = mysql_query(conectar, i);
					if (!q_estado) {
						cout << "Ingreso exitoso" << endl;
						cout << "\n";
					}
					else {
						cout << "Error al ingresar" << endl;
						cout << "\n";
					}
					break;

				case 4:

					break;

				}

				break;

			}
		} 		while (op != 3);


	}
	else {
		cout << "error al conectar" << endl;
	}
	system("pause");
	return 0;

}
*/