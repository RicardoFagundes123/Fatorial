import React, { Component } from 'react';
import {
    StyleSheet,
    Text,
    View,
    Image
} from 'react-native';
import {Icon} from 'react-native-elements';

export default class Menu extends Component {
    render() {
        return (
            <View style={styles.container}>
                <Image  
                    source = {require('.././assets/logo2.png')} 
                    style={styles.fot}/>
                <View style={styles.card1}>
                    <Icon
                        name='face'
                        //type='font-awesome'
                        color='#4d79ff'
                        size= {50}

                        onPress={() => this.props.navigation.navigate('Profile')}
                    />
                    <Text style={styles.title}>
                        Perfil
                    </Text>
                </View>
                <View style={styles.card2}>
                    <Icon
                        name='kitchen'
                        color='#4d79ff'
                        size= {50}
                        onPress={() => this.props.navigation.navigate('Tools')}
                    />
                    <Text style={styles.title}>
                        Equipamentos
                    </Text>
                </View>
                <View style={styles.card3}>
                    <Icon
                        name='highlight'
                        //type='font-awesome'
                        color='#4d79ff'
                        size= {56}
                        onPress={() => this.props.navigation.navigate('showData')}
                    />
                    <Text style={styles.title3}>
                        Consultar Gastos
                    </Text>
                </View>
                <View style={styles.card4}>
                    <Icon
                        name='database'
                        type='font-awesome'
                        color='#4d79ff'
                        size= {42}
                        onPress={() => this.props.navigation.navigate('addData')}
                    />
                    <Text style={styles.title2}>
                        Adicionar Dados
                    </Text>
                </View>
            </View>
        );
    }
}


const styles = StyleSheet.create({
    container:{
        flex: 1,
        justifyContent: 'center',
        //alignItems: 'stretch',
        flexDirection: 'column',
        backgroundColor: 'white',
    },
    title:{
        fontSize: 20,
        textAlign: 'center',
        margin: 8
    },
    title2:{
        fontSize: 20,
        textAlign: 'center',
        margin: 8,
        marginLeft: 14
    },
    title3:{
        fontSize: 20,
        textAlign: 'center',
        margin: 8,
        marginLeft: 5
    },
    card1:{
        flex: 1,
        justifyContent: 'center',
        alignItems: 'center',
        flexDirection: 'row',
        marginRight: 232,
        marginLeft: 14
    },
    card2:{
        flex: 1,
        justifyContent: 'center',
        alignItems: 'center',
        flexDirection: 'row',
        marginRight: 146,
        marginLeft: 8
    },
    card3:{
        flex: 1,
        justifyContent: 'center',
        alignItems: 'center',
        flexDirection: 'row',
        marginRight: 124,
        marginLeft: 10,
    },
    card4:{
        flex: 1,
        justifyContent: 'center',
        alignItems: 'center',
        flexDirection: 'row',
        marginRight: 114,
    },
    fot:{
        width: 350,
        height: 141,    
        borderRadius: 10
    }
})